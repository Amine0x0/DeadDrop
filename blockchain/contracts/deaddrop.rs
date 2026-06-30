use anchor_lang::prelude::*;

//contract address
declare_id!("");

#[program]
pub mod dead_drop {
    use super::*;

    pub fn initialize(ctx: Context<Initialize>, cid: String, price: u64) -> Result<()> {
        let escrow = &mut ctx.accounts.escrow;
        escrow.cid = cid;
        escrow.price = price;
        escrow.is_paid = false;
        Ok(())
    }
}

#[derive(Accounts)]
pub struct Initialize<'info> {
    #[account(init, payer = user, space = 8 + 64 + 8 + 1)]
    pub escrow: Account<'info, Escrow>,
    #[account(mut)]
    pub user: Signer<'info>,
    pub system_program: Program<'info, System>,
}

#[account]
pub struct Escrow {
    pub cid: String,
    pub price: u64,   
    pub is_paid: bool,
}